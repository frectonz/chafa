use chafa::ChafaCanvas;
use ocaml_interop::{ocaml_export, OCaml, OCamlInt, OCamlRef, ToOCaml};

ocaml_export! {
    fn draw_image(cr, path: OCamlRef<String>, width: OCamlRef<OCamlInt>, height: OCamlRef<OCamlInt>) -> OCaml<String> {
        let path: String = path.to_rust(cr);
        let img = image::open(path).expect("Failed to open image");

        let width: i32 = width.to_rust(cr);
        let height: i32 = height.to_rust(cr);
        let canvas = ChafaCanvas::new(width as u32, height as u32);
        let pixels = img.to_rgba8();

        let out = canvas.draw(&pixels, img.width(), img.height());

        out.to_ocaml(cr)
    }
}
