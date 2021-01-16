module Classes = {
  type t = {
    .
    "root": option(string),
    "tile": option(string),
    "imgFullHeight": option(string),
    "imgFullWidth": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~tile: string=?,
      ~imgFullHeight: string=?,
      ~imgFullWidth: string=?,
      unit
    ) =>
    t;
};

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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~cols: MaterialUi_Types.Number.t=?,
    ~component: Component.t=?,
    ~rows: MaterialUi_Types.Number.t=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "GridListTile";
