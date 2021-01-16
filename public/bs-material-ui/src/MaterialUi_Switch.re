module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module TabIndex: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

module Type_enum: {
  type t;
  let button: t;
  let reset: t;
  let submit: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let button = Any("button");
  let reset = Any("reset");
  let submit = Any("submit");
};

module Type: {
  type t;
  let enum: Type_enum.t => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Type_enum.t) => Any(v);
  let string = (v: string) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(string),
    "edgeStart": option(string),
    "edgeEnd": option(string),
    "switchBase": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "sizeSmall": option(string),
    "checked": option(string),
    "disabled": option(string),
    "input": option(string),
    "thumb": option(string),
    "track": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~edgeStart: string=?,
      ~edgeEnd: string=?,
      ~switchBase: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~sizeSmall: string=?,
      ~checked: string=?,
      ~disabled: string=?,
      ~input: string=?,
      ~thumb: string=?,
      ~track: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Primary | `Secondary];

module Edge: {
  type t;
  let _end: t;
  let start: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _end = Any("end");
  let start = Any("start");
  let _false = Any(false);
};

type size = [ | `Medium | `Small];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: bool=?,
    ~component: Component.t=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~href: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onDragLeave: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onFocusVisible: MaterialUi_Types.any=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?,
    ~onTouchEnd: ReactEvent.Touch.t => unit=?,
    ~onTouchMove: ReactEvent.Touch.t => unit=?,
    ~onTouchStart: ReactEvent.Touch.t => unit=?,
    ~tabIndex: TabIndex.t=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: Type.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: 'children=?,
    ~disableFocusRipple: bool=?,
    ~checked: bool=?,
    ~checkedIcon: React.element=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "default"] `Default
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~edge: Edge.t=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~required: bool=?,
    ~size: [@bs.string] [
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~value: MaterialUi_Types.any=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Switch";
