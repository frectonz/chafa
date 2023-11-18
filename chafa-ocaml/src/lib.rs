use chafa::ChafaCanvas;
use ocaml_interop::{ocaml_export, OCaml, OCamlRef, ToOCaml};

ocaml_export! {
    fn draw_image(cr, path: OCamlRef<String>) -> OCaml<String> {
        let path: String = path.to_rust(cr);
        let img = image::open(path).expect("Failed to open image");

        let canvas = ChafaCanvas::from_term(img.width(), img.height());
        let pixels = img.to_rgba8();

        let out = canvas.draw(&pixels, img.width(), img.height());

        out.to_ocaml(cr)
    }
}
