module Classes = {
  type t = {
    .
    "root": option(string),
    "media": option(string),
    "img": option(string),
  };
  [@bs.obj]
  external make:
    (~root: string=?, ~media: string=?, ~img: string=?, unit) => t;
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
    ~component: Component.t=?,
    ~image: string=?,
    ~src: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "CardMedia";
