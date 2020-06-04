module MaxWidth = {
  type t = [ | `Xs | `Sm | `Md | `Lg | `Xl | `False];
  let tToJs =
    fun
    | `Xs => "xs"->Obj.magic
    | `Sm => "sm"->Obj.magic
    | `Md => "md"->Obj.magic
    | `Lg => "lg"->Obj.magic
    | `Xl => "xl"->Obj.magic
    | `False => false->Obj.magic;
};

module Classes = {
  type classesType =
    | Root(string)
    | DisableGutters(string)
    | Fixed(string)
    | MaxWidthXs(string)
    | MaxWidthSm(string)
    | MaxWidthMd(string)
    | MaxWidthLg(string)
    | MaxWidthXl(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | DisableGutters(_) => "disableGutters"
    | Fixed(_) => "fixed"
    | MaxWidthXs(_) => "maxWidthXs"
    | MaxWidthSm(_) => "maxWidthSm"
    | MaxWidthMd(_) => "maxWidthMd"
    | MaxWidthLg(_) => "maxWidthLg"
    | MaxWidthXl(_) => "maxWidthXl";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | DisableGutters(className)
                         | Fixed(className)
                         | MaxWidthXs(className)
                         | MaxWidthSm(className)
                         | MaxWidthMd(className)
                         | MaxWidthLg(className)
                         | MaxWidthXl(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rnbe=?,
    ~disableGutters: bool=?,
    ~fixed: bool=?,
    ~maxWidth: 'any_rjyo=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~disableGutters: option(bool)=?,
      ~fixed: option(bool)=?,
      ~maxWidth: option(MaxWidth.t)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableGutters?,
    ~fixed?,
    ~maxWidth=?maxWidth->Belt.Option.map(v => MaxWidth.tToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Container";
