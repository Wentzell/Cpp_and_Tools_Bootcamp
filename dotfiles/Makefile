# Install ./dotfile in ~/.dotfile by symlink, unless it's already done.
# Try -r first since it's nicer, but only works on GNU ln.
$(HOME)/.%: %
	[[ $@ -ef $< ]] || \
		ln -snr $< $@ 2>/dev/null || \
		ln -sn $(PWD)/$< $@

# Install all files added to git:
files:=$(filter-out Makefile,$(shell git ls-files))
# You could also set this to all files in the directory:
#files:=$(filter-out Makefile,$(wildcard *))
# Or to an explicit list of files:
#files=
#files+=gitconfig
#files+=tmux.conf

.PHONY: install
install: $(addprefix $(HOME)/.,$(files))
