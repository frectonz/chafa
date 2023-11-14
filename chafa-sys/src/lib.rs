#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]
#![allow(clippy::useless_transmute)]
#![allow(clippy::approx_constant)]
#![allow(clippy::too_many_arguments)]
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use std::ffi::CString;

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

        let symbol_map = unsafe {
            let symbol_map = crate::chafa_symbol_map_new();
            crate::chafa_symbol_map_add_by_tags(
                symbol_map,
                crate::ChafaSymbolTags_CHAFA_SYMBOL_TAG_ALL,
            );
            symbol_map
        };

        let config = unsafe {
            let config = crate::chafa_canvas_config_new();
            crate::chafa_canvas_config_set_geometry(config, 23, 12);
            crate::chafa_canvas_config_set_symbol_map(config, symbol_map);
            config
        };

        let canvas = unsafe { crate::chafa_canvas_new(config) };

        unsafe {
            crate::chafa_canvas_draw_all_pixels(
                canvas,
                crate::ChafaPixelType_CHAFA_PIXEL_RGBA8_UNASSOCIATED,
                pixels.as_ptr(),
                PIX_WIDTH as i32,
                PIX_HEIGHT as i32,
                (PIX_WIDTH * N_CHANNELS) as i32,
            );
        }

        let gstring = unsafe { crate::chafa_canvas_build_ansi(canvas) };
        let ansistr = unsafe { (*gstring).str_ };
        let ansistr = unsafe { CString::from_raw(ansistr) };
        let ansistr = ansistr.to_string_lossy();

        println!("{}", ansistr);

        unsafe {
            // crate::g_string_free(gstring, 1);
            crate::chafa_canvas_unref(canvas);
            crate::chafa_canvas_config_unref(config);
            crate::chafa_symbol_map_unref(symbol_map);
        }

        assert!(true);
    }

    #[test]
    fn frectonz_image() {
        let img = image::open("frectonz.png").expect("Failed to open image");

        let symbol_map = unsafe {
            let symbol_map = crate::chafa_symbol_map_new();
            crate::chafa_symbol_map_add_by_tags(
                symbol_map,
                crate::ChafaSymbolTags_CHAFA_SYMBOL_TAG_ALL,
            );
            symbol_map
        };

        let (terminal_size::Width(cols), terminal_size::Height(rows)) =
            terminal_size::terminal_size().expect("couldn't get term width and height");

        let width_ptr: *mut i32 = &mut (cols as i32);
        let height_ptr: *mut i32 = &mut (rows as i32);

        unsafe {
            crate::chafa_calc_canvas_geometry(
                img.width() as i32,
                img.height() as i32,
                width_ptr,
                height_ptr,
                0.5,
                false.into(),
                false.into(),
            );
        }

        let config = unsafe {
            let config = crate::chafa_canvas_config_new();
            crate::chafa_canvas_config_set_geometry(config, *width_ptr, *height_ptr);
            crate::chafa_canvas_config_set_symbol_map(config, symbol_map);
            config
        };

        let canvas = unsafe { crate::chafa_canvas_new(config) };
        let pixels = img.to_rgba8();

        unsafe {
            crate::chafa_canvas_draw_all_pixels(
                canvas,
                crate::ChafaPixelType_CHAFA_PIXEL_RGBA8_UNASSOCIATED,
                pixels.as_ptr(),
                img.width() as i32,
                img.height() as i32,
                (img.width() * 4) as i32,
            );
        }

        let gstring = unsafe { crate::chafa_canvas_build_ansi(canvas) };
        let ansistr = unsafe { (*gstring).str_ };
        let ansistr = unsafe { CString::from_raw(ansistr) };
        let ansistr = ansistr.to_string_lossy();

        println!("{}", ansistr);

        unsafe {
            // crate::g_string_free(gstring, 1);
            crate::chafa_canvas_unref(canvas);
            crate::chafa_canvas_config_unref(config);
            crate::chafa_symbol_map_unref(symbol_map);
        }

        assert!(true);
    }
}
