use std::env;
use std::path::PathBuf;

fn main() {
    let chafa_lib = pkg_config::probe_library("chafa");

    println!("cargo:rerun-if-changed=build.rs");

    match chafa_lib {
        Ok(lib) => chafa_installed(lib),
        Err(_) => build_chafa(),
    };
}

fn build_chafa() {
    let dst = autotools::Config::new("vendor/chafa-1.12.5")
        .config_option("quiet", None)
        .build();

    println!("cargo:rustc-link-search=native={}", dst.display());

    let chafa_lib = pkg_config::probe_library("chafa").unwrap();
    chafa_installed(chafa_lib);
}

fn chafa_installed(lib: pkg_config::Library) {
    println!("cargo:rustc-link-lib=chafa");
    println!("cargo:rerun-if-changed=wrapper.h");

    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .clang_args(
            lib.include_paths
                .iter()
                .map(|path| path.to_str().unwrap())
                .map(|path| format!("-I{path}")),
        )
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
