./simplebuild ubu14install

./simplebuild debinstall

./simplebuild menu

./simplebuild cedit - edit script options

./simplebuild lang_select - switch/select script language 

./simplebuild checkout XXXX - get the last svn (XXXX is optional for revision)

./simplebuild toolchainname loadonly - fetch the toolchain only

./simplebuild clean - cleanup (archiv,configs,oscam-svn,simplebuild.config,build.log) not toolchains & toolchain backups

./simplebuild reset_all - delete everything except the simplebuild script itself

./simplebuild debinstall - install all needed packages for building 

./simplebuild checksys - check installed packages

mkdir simplebuild

cd simplebuild

wget ss4200.homelinux.com/oscam/simplebuild

chmod 777 simplebuild