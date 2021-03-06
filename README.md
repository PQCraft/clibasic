# CLIBASIC <br>
<!----> <br>
### <ins>C</ins>ommand <ins>L</ins>ine <ins>I</ins>nterface <ins>B</ins>eginners <ins>A</ins>ll-purpose <ins>S</ins>ymbolic <ins>I</ins>nstruction <ins>C</ins>ode <br>
CLIBASIC is a version of BASIC designed to run in the command line or terminal
<!----> <br>
[![image](docs/clibasic_logo_rounded.png)](#?)
<!----> <br>
---
### Required Packages/Programs <br>
#### Linux <br>
Debian (`apt`): `build-essential`, `libreadline-dev` <br>
Arch (`pacman`): `base-devel`, `readline` <br>
Alpine (`apk`): `build-base`, `readline-dev` <br>
#### Windows <br>
NT - 10 (download): [`MinGW`](http://mingw-w64.org/doku.php/download/mingw-builds), [`Make for Windows`](http://gnuwin32.sourceforge.net/packages/make.htm) <br>
7 - 10 (`choco`): `mingw`, `make` <br>
#### MacOS <br>
Mojave - Big Sur (`brew`): `gcc`, `make`, `readline` <br>

---
### Recommended Packages/Programs <br>
#### Linux <br>
Debian (`apt`): `git` <br>
Arch (`pacman`): `git` <br>
Alpine (`apk`): `git` <br>
#### Windows <br>
NT - 10 (download): [`git`](https://git-scm.com/download/win) <br>
7 - 10 (`choco`): `git` <br>
#### MacOS <br>
Mojave - Big Sur (`brew`): `git` <br>

---
### Building and Running <br>
#### Linux/Windows/MacOS <br>
To build, use `make build`. <br>
To run, use `make run` or `./clibasic`. <br>
To build then run, use `make` (same as `make all`). <br>

---
### Notes <br>
- You can install CLIBASIC using the [`clibasic`](https://aur.archlinux.org/packages/clibasic/) or [`clibasic-bin`](https://aur.archlinux.org/packages/clibasic-bin/) AUR packages.
- On Linux if CLIBASIC is not run in a terminal it will attempt to open in XTerm. CLIBASIC will only read arguments if it is run in a terminal.
- If the file `.clibasic_history` is present in the user's home directory CLIBASIC will automatically save history there. Run `_AUTOCMDHIST`, `_SAVECMDHIST` (without any arguments), or create the file `.clibasic_history` in your home/user folder to enable this feature. Remove the file to disable this feature.
- CLIBASIC will look for `AUTORUN.BAS` (and `autorun.bas` on Linux) in the user's home directory and run the file if present.
- Any Windows before Windows 10 build 16257 will not display correctly due to the lack of ANSI escape code sequnce support.
- The development scripts are `build.sh` which is for testing if CLIBASIC compiles correctly for Linux and Windows, and `package.sh` which creates the zip files for making a CLIBASIC release.
