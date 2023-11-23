{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    rust-overlay = {
      url = "github:oxalica/rust-overlay";
      inputs = {
        nixpkgs.follows = "nixpkgs";
        flake-utils.follows = "flake-utils";
      };
    };
  };
  outputs = { self, nixpkgs, flake-utils, rust-overlay }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        overlays = [ (import rust-overlay) ];
        pkgs = import nixpkgs {
          inherit system overlays;
        };

        essentials = with pkgs; [
          glib
          chafa
          freetype
          pkg-config
        ];
      in
      with pkgs;
      {

        devShells.default = mkShell.override { stdenv = clangStdenv; } {
          buildInputs = essentials ++ [
            rust-bin.stable.latest.default
            rust-analyzer
            nil

            dune_3
            ocaml
          ];
          LIBCLANG_PATH = "${pkgs.libclang.lib}/lib";
        };

        formatter = nixpkgs-fmt;
      }
    );
}
