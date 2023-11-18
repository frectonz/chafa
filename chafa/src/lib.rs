use std::ffi::CString;

pub struct ChafaCanvas {
    symbol_map: *mut chafa_sys::ChafaSymbolMap,
    config: *mut chafa_sys::ChafaCanvasConfig,
    canvas: *mut chafa_sys::ChafaCanvas,
}

impl ChafaCanvas {
    pub fn new(width: u32, height: u32) -> Self {
        let symbol_map = unsafe {
            let symbol_map = chafa_sys::chafa_symbol_map_new();
            chafa_sys::chafa_symbol_map_add_by_tags(
                symbol_map,
                chafa_sys::ChafaSymbolTags_CHAFA_SYMBOL_TAG_ALL,
            );
            symbol_map
        };

        let config = unsafe {
            let config = chafa_sys::chafa_canvas_config_new();
            chafa_sys::chafa_canvas_config_set_geometry(config, width as i32, height as i32);
            chafa_sys::chafa_canvas_config_set_symbol_map(config, symbol_map);
            config
        };

        let canvas = unsafe { chafa_sys::chafa_canvas_new(config) };

        Self {
            symbol_map,
            config,
            canvas,
        }
    }

    pub fn from_term(src_width: u32, src_height: u32) -> Self {
        let symbol_map = unsafe {
            let symbol_map = chafa_sys::chafa_symbol_map_new();
            chafa_sys::chafa_symbol_map_add_by_tags(
                symbol_map,
                chafa_sys::ChafaSymbolTags_CHAFA_SYMBOL_TAG_ALL,
            );
            symbol_map
        };

        let (terminal_size::Width(cols), terminal_size::Height(rows)) =
            terminal_size::terminal_size()
                .unwrap_or((terminal_size::Width(100), terminal_size::Height(50)));

        let width_ptr: *mut i32 = &mut (cols as i32);
        let height_ptr: *mut i32 = &mut (rows as i32);

        unsafe {
            chafa_sys::chafa_calc_canvas_geometry(
                src_width as i32,
                src_height as i32,
                width_ptr,
                height_ptr,
                0.5,
                false.into(),
                false.into(),
            );
        }

        let config = unsafe {
            let config = chafa_sys::chafa_canvas_config_new();
            chafa_sys::chafa_canvas_config_set_geometry(config, *width_ptr, *height_ptr);
            chafa_sys::chafa_canvas_config_set_symbol_map(config, symbol_map);
            config
        };

        let canvas = unsafe { chafa_sys::chafa_canvas_new(config) };

        Self {
            symbol_map,
            config,
            canvas,
        }
    }

    pub fn draw(&self, pixels: &[u8], pix_width: u32, pix_height: u32) -> String {
        let channels = 4; // four channels: red, green, blue, alpha

        unsafe {
            chafa_sys::chafa_canvas_draw_all_pixels(
                self.canvas,
                chafa_sys::ChafaPixelType_CHAFA_PIXEL_RGBA8_UNASSOCIATED,
                pixels.as_ptr(),
                pix_width as i32,
                pix_height as i32,
                (pix_width * channels) as i32,
            );
        }

        let gstring = unsafe { chafa_sys::chafa_canvas_build_ansi(self.canvas) };
        let ansistr = unsafe { (*gstring).str_ };
        let ansistr = unsafe { CString::from_raw(ansistr) };
        let ansistr = ansistr.to_string_lossy();

        ansistr.to_string()
    }
}

impl Drop for ChafaCanvas {
    fn drop(&mut self) {
        unsafe {
            chafa_sys::chafa_canvas_unref(self.canvas);
            chafa_sys::chafa_canvas_config_unref(self.config);
            chafa_sys::chafa_symbol_map_unref(self.symbol_map);
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::ChafaCanvas;

    #[test]
    fn usage_example() {
        const PIX_WIDTH: usize = 3;
        const PIX_HEIGHT: usize = 3;
        const N_CHANNELS: usize = 4;

        let pixels: [u8; PIX_WIDTH * PIX_HEIGHT * N_CHANNELS] = [
            0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00,
            0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff,
            0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff,
        ];

        let canvas_width = 25;
        let canvas_height = 10;
        let canvas = ChafaCanvas::new(canvas_width, canvas_height);
        let ansi = canvas.draw(&pixels, PIX_WIDTH as u32, PIX_HEIGHT as u32);
        println!("{ansi}");
    }

    #[test]
    fn frectonz_image() {
        let img = image::open("/home/frectonz/workspace/chafa/chafa-sys/frectonz.png")
            .expect("failed to open image");

        let canvas = ChafaCanvas::from_term(img.width(), img.height());
        let pixels = img.to_rgba8();
        let ansi = canvas.draw(&pixels, img.width(), img.height());

        println!("{ansi}");
    }
}
