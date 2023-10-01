{
	description = "CPE 211 activities";

	inputs = {
		nixpkgs = {
			url = "github:NixOS/nixpkgs/release-23.05";
		};

		utils = { 
			url = "github:numtide/flake-utils";
			inputs.nixpkgs.follows = "nixpkgs";
		};
	};

	outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
		"x86_64-linux" "i686-linux" "aarch64-linux" "x86_64-darwin"
	] (
		system: let pkgs = import nixpkgs {
			inherit system;
		};
		in {
			devShell = pkgs.mkShell rec {
				name = "cpe211";

				packages = with pkgs; [
					# Development Tools
					llvmPackages_11.clang
					cmake
					cmakeCurses
					ncurses
				];
				shellHook = let
				icon = "f121";
				in ''
					export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
				'';
			};
		}
	);
}
