module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~raised: bool=?,
    ~component: 'union_r1q3=?,
    ~elevation: 'number_a=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Card/Card"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~raised: option(bool)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~raised?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~square?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
