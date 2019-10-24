---
customTheme : "flatiron"
progress: false
theme: solarized
controlsTutorial: false
help: false
transition: 'fade'
hideAddressBar: true
showNotes: false
titlebar: false
viewDistance: 1
highlightTheme: "Xcode"
enableTitleFooter: false
enableMenu: false
enableChalkboard: false
enableZoom: false
enableSearch: false
autoSlidePlayer: false
slideNumber: false
playback: false
autoSlide: false
---

# Editing & <br> Static Analysis

### Philipp T. Dumitrescu

---

## Integrate Development Environments (IDEs)

* Find a system of development that **works for you**
* But it should be:
    - Fast for you
    - Extensible
    - Bug Protecting
    - Feature Revealing?
* Good Choices: VSCode, CLion, [maybe Vim with Extensions]

--

## VSCode

* Developed by Microsoft; mostly unrelated to VisualStudio
* Chromium based:
    - Advantages: many-plugins (JavaScript), cross-platform
    - Disadvantages: Non-native, speed (maybe), memory intensive
* Good community support
* Test-bed for IDE development
* Available on cluster / workstations: `nix/vscode/1.39.1`

---

## Static Analysis

* Analyze software without execute it
* Complier does this (& changes code but same result)
* This means the compiler has a huge amount of information
* **In general compilers are smarter than you are**
* Use this machinery:
    - Error message
    - Warnings 
    - Security warnings
    - Code improvements
* Good code can be analyzed and optimized automatically <br> (This affects your coding style.)

---

## Clang-Format

* Enforce consistent formatting / styling
* Easy to read == Easy to understand logic & find bugs
* Make things consistent in large projects 
* Advanced: read motivation for style guide & coding guide
    - CppCoreGuidelines: (later)
    - Google: https://google.github.io/styleguide/cppguide.html
    - LLVM: https://llvm.org/docs/CodingStandards.html
* (Demo)

---

## Clang-Tidy / Language Server Protocol 

* Clang-Tidy is LLVM/clang based "language smarts"
    - code completion
    - errors / warnings
    - go-to-definition
    - etc.
* Need to pass information between different programs
* LSP standardized by Microsoft: clangd for clang-tidy

---

## CppCoreGuidelines

* http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
* Effort to educate & enforce good modern practices
* Long list (daunting!)
* Good to selectively browse through
* clang-tidy can automatically recommend updates
* Examples

---

##  Demo to set-up clangd in VSCode using cmake

* Caveat: cmake does not give all information

```bash
compdb -p ../build/ list > compile_commands.json 
```

* (Examples)

---

## Resources

 * http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
 * https://clang.llvm.org/extra/clang-tidy
 * https://microsoft.github.io/language-server-protocol/overview
 * https://clang.llvm.org/extra/clangd
