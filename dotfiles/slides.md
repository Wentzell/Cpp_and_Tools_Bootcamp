### Keeping dotfiles in git

Keep your configuration files in a git repository!

#### Examples

* https://github.com/pappasam/dotfiles
* https://github.com/Wentzell/dotfiles
* https://github.com/dylex/skel
* 127,323 others: https://github.com/search?q=dotfiles


#### Advantages:

* Versioning: try out new config changes, revert to old ones
* Consistency: easily setup a new account/machine and propagate changes
* Transparency: share your discoveries with the world (or, don't: no github/gitlab necessary)

#### Disadvantages

* Extra work: commit changes (on occasion)



## Setup

1. Create a new git repo
1. Start adding dotfiles
   * `cp ~/.gitconfig gitconfig`
   * `git add gitconfig`
1. Make a way to "install" files into home
   * Link, symlink, or copy
   * Simple script with loop
   * [Makefile](Makefile)

```make
$(HOME)/.%: %
	[[ $@ -ef $< ]] || \
		ln -snr $< $@

files:=$(filter-out Makefile,$(shell git ls-files))

install: $(addprefix $(HOME)/.,$(files))
```


## New machine

1. Clone repo
1. Branch for different environments (or make installer or config conditional)
1. Install
