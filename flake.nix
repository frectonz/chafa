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
    crane = {
      url = "github:ipetkov/crane";
      inputs = {
        nixpkgs.follows = "nixpkgs";
      };
    };
  };
  outputs = { self, nixpkgs, flake-utils, rust-overlay, crane }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        overlays = [ (import rust-overlay) ];
        pkgs = import nixpkgs {
          inherit system overlays;
        };

        craneLib = crane.lib.${system};
        src = craneLib.cleanCargoSource ./.;

        commonArgs = { inherit src; };

        cargoArtifacts = craneLib.buildDepsOnly commonArgs;
        bin = craneLib.buildPackage (commonArgs // {
          inherit cargoArtifacts;
        });
      in
      with pkgs;
      {
        packages = {
          inherit bin;
          default = bin;
        };

        devShells.default = mkShell.override { stdenv = clangStdenv; } {
          buildInputs = [
            rust-bin.stable.latest.default
            rust-analyzer
            nil

            glib
            chafa
            freetype
            pkg-config
          ];
          LIBCLANG_PATH = "${pkgs.libclang.lib}/lib";
        };

        formatter = nixpkgs-fmt;
      }
    );
}
