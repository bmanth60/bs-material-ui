module BackdropComponent: {
  type t;
  let string: string => t;
  let backdropComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let backdropComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Container: {
  type t;
  let custom: Dom.element => t;
  let element: React.element => t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let custom = (v: Dom.element) => Any(v);
  let element = (v: React.element) => Any(v);
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(string),
    "scrollPaper": option(string),
    "scrollBody": option(string),
    "container": option(string),
    "paper": option(string),
    "paperScrollPaper": option(string),
    "paperScrollBody": option(string),
    "paperWidthFalse": option(string),
    "paperWidthXs": option(string),
    "paperWidthSm": option(string),
    "paperWidthMd": option(string),
    "paperWidthLg": option(string),
    "paperWidthXl": option(string),
    "paperFullWidth": option(string),
    "paperFullScreen": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~scrollPaper: string=?,
      ~scrollBody: string=?,
      ~container: string=?,
      ~paper: string=?,
      ~paperScrollPaper: string=?,
      ~paperScrollBody: string=?,
      ~paperWidthFalse: string=?,
      ~paperWidthXs: string=?,
      ~paperWidthSm: string=?,
      ~paperWidthMd: string=?,
      ~paperWidthLg: string=?,
      ~paperWidthXl: string=?,
      ~paperFullWidth: string=?,
      ~paperFullScreen: string=?,
      unit
    ) =>
    t;
};

module MaxWidth: {
  type t;
  let lg: t;
  let md: t;
  let sm: t;
  let xl: t;
  let xs: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let lg = Any("lg");
  let md = Any("md");
  let sm = Any("sm");
  let xl = Any("xl");
  let xs = Any("xs");
  let _false = Any(false);
};

module PaperComponent: {
  type t;
  let string: string => t;
  let paperComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let paperComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

type scroll = [ | `Body | `Paper];

module TransitionComponent: {
  type t;
  let string: string => t;
  let transitionComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module TransitionDuration_shape = {
  type t = {
    .
    "appear": option(MaterialUi_Types.Number.t),
    "enter": option(MaterialUi_Types.Number.t),
    "exit": option(MaterialUi_Types.Number.t),
  };
  [@bs.obj]
  external make:
    (
      ~appear: MaterialUi_Types.Number.t=?,
      ~enter: MaterialUi_Types.Number.t=?,
      ~exit: MaterialUi_Types.Number.t=?,
      unit
    ) =>
    t;
};

module TransitionDuration: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: TransitionDuration_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: TransitionDuration_shape.t) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~_BackdropComponent: BackdropComponent.t=?,
    ~closeAfterTransition: bool=?,
    ~container: Container.t=?,
    ~disableAutoFocus: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disablePortal: bool=?,
    ~disableRestoreFocus: bool=?,
    ~disableScrollLock: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~aria_describedby: string=?,
    ~aria_labelledby: string=?,
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disableBackdropClick: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~fullScreen: bool=?,
    ~fullWidth: bool=?,
    ~maxWidth: MaxWidth.t=?,
    ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
    ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperComponent: PaperComponent.t=?,
    ~_PaperProps: Js.t({..})=?,
    ~scroll: [@bs.string] [ | [@bs.as "body"] `Body | [@bs.as "paper"] `Paper]
               =?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Dialog";
