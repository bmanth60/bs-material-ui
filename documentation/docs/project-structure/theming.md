---
title: Theming
---

## `classes` prop

Overriding styles locally is usually done via the `classes` prop that exists on
virtually every component. Likewise, each component of the bindings has this
prop and an according generator function for it. It is accessible via
`MaterialUi.Component.Classes.make`.

Example:

```reason
open MaterialUi;
let classes = Styles.useStyles();
<Paper
  classes={Paper.Classes.make(
    ~root=classes.root,
    ~rounded=classes.rounded,
    (),
  )}>
  <Typography> {"Some Content"->React.string} </Typography>
</Paper>
```

## On themes in general

The automated generation of the theme object differs a bit from the components.
The theme is extracted from it's typescript definitions, which are quite
complex. This means that the extraction process is a bit error prone
(unfortunately a lot more than I'd like). This means that it is possible for the
theme functions / object to change from release to release in a seemingly random
fashion, until I can resolve this situation in a reliable way (Not a trivial
problem to solve unfortunately).

Theming is split into two modules:

- `MaterialUi_Theme` (reading)
- `MaterialUi_ThemeOptions` (constructing)

Theme definitions are likely to undergo breaking changes in future versions.

## Constructing a theme

You can construct a theme object by calling `MaterialUi.ThemeOptions.make`. You
would usually pass it to the `createMuiTheme` function, which has a binding for
convenience at : `MaterialUi.Theme.create`.

The following is an example of constructing a theme object:

```reason
let theme =
  MaterialUi_Theme.create({
    open MaterialUi_ThemeOptions;
    make(
    ~overrides=
        Overrides.make(
        ~muiButton=
            ButtonClassKey.make(
            ~outlined=
                ReactDOMRe.Style.make(
                ~fontSize="12px",
                ~fontWeight="300",
                ~color="gray",
                (),
                ),
            (),
            ),
        (),
        ),
    (),
    )
  });
```

You might have noticed that `ButtonClassKey` is not a straight forward and easy
to guess sub module name. This is due to how the type information is presented
by typescript. When in doubt, just open the `MaterialUi_ThemeOptions.re` module
and follow the module names.

## Reading from a theme

Reading from a theme object has become a lot more straight forward in the latest
ReScript versions (as records are now equivalent to JavaScript objects).

All (sub-)types are in a flat hierarchy inside the `MaterialUi_Theme` module.
Accessing them is very straight forward and corresponds to the original
MaterialUi Shape.

Here are 2 examples of accessing fields in the theme object:

```reason
@react.component
let make = () => {
  let theme = MaterialUi.Core.useTheme();

  <div style={ReactDOMRe.Style.make(~color=theme.palette.primary.main, ())}>
    {"Some main colored text"->React.string}
  </div>
}
```

```reason
module Styles = %makeStyles(
  theme => {
    toolbarIcon: ReactDOMRe.Style.combine(
      ReactDOMRe.Style.make(
        ~padding="0 8px",
        (),
      ),
      theme.mixins.toolbar,
    ),
    appBar: ReactDOMRe.Style.make(
      ~zIndex=(theme.zIndex.drawer +. 1.0)->int_of_float->string_of_int,
      ~transition=MaterialUi.ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~affectMargin=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.leavingScreen,
        (),
      ),
      (),
    ),
  }
)
```

(The above example makes mention of the user contributed
`MaterialUi.ThemeHelpers` module. Please refer to the source code for more
information.)

## Theme Provider

For providing a theme at root level or further down the tree, you should use the
`MaterialUi_ThemeProvider` component.

Example:

```reason
let theme = MaterialUi.Theme.create(MaterialUi.ThemeOptions.make());

@react.component
let make = () => {
  <div className="app root">
    <MaterialUi_ThemeProvider theme>
      <div />
    </MaterialUi_ThemeProvider>
  </div>
}
```
