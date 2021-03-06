# samp-loadingbar

[![sampctl](https://img.shields.io/badge/sampctl-samp--loadingbar-2f2f2f.svg?style=for-the-badge)](https://github.com/LuminouZ307/samp-loadingbar)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install LuminouZ307/samp-loadingbar
```

Include in your code and begin using the library:

```pawn
#include <samp-loadingbar>
```

## Usage

### Functions

* `StartPlayerLoadingBar(playerid, value = 3, const text[] = "_", interval = 1000, const callback[] = EOS, color = 1687547311)` :

  * Create player a LoadingBar
  
  * playerid = The player ID you wan't to show the LoadingBar.
  * value = The maximum value for the LoadingBar.
  * text = The text when LoadingBar showed.
  * interval = The uLoadingBar update interval.
  * callback = The function/callback that called when the LoadingBar finished.
  * color = The color for LoadingBar (default are 1687547311, you can use color format like '0xFF0000FF').

* `StopPlayerLoadingBar(playerid)` :

  * Stop current player LoadingBar (if exists).

* `IsValidLoadingBar(playerid)` :

  * Check if player have active LoadingBar or no.

### Callbacks

* `OnLoadingBarProgress(playerid, value)` :

  * Detect every LoadingBar value updated.
  * value = current value when updated.

* `OnLoadingBarFinished(playerid)` :

  * Detect when current player LoadingBar finished.

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
