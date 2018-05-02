[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | Select(string)
    | SelectMenu(string)
    | Disabled(string)
    | Icon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Select(_) => "select"
    | SelectMenu(_) => "selectMenu"
    | Disabled(_) => "disabled"
    | Icon(_) => "icon";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Select(className)
             | SelectMenu(className)
             | Disabled(className)
             | Icon(className) =>
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
    ~autoWidth: bool=?,
    ~displayEmpty: bool=?,
    ~input: ReasonReact.reactElement=?,
    ~inputProps: Js.t({..})=?,
    ~_MenuProps: Js.t({..})=?,
    ~multiple: bool=?,
    ~native: bool=?,
    ~onChange: 'any_rfe8=?,
    ~onClose: 'any_ry4w=?,
    ~onOpen: 'any_r8nv=?,
    ~_open: bool=?,
    ~renderValue: 'any_r8qt=?,
    ~_SelectDisplayProps: Js.t({..})=?,
    ~value: 'union_ruwa=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'union_r3rg=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: ReasonReact.reactElement=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_ro5v=?,
    ~inputRef: 'genericCallback=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onEmpty: 'genericCallback=?,
    ~onFilled: 'genericCallback=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~rows: 'union_ra0q=?,
    ~rowsMax: 'union_r2or=?,
    ~startAdornment: ReasonReact.reactElement=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Select/Select"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~autoWidth: option(bool)=?,
      ~displayEmpty: option(bool)=?,
      ~input: option(ReasonReact.reactElement)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~_MenuProps: option(Js.t({..}))=?,
      ~multiple: option(bool)=?,
      ~native: option(bool)=?,
      ~onChange: option((ReactEventRe.Form.t, Js.t({..})) => unit)=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onOpen: option(ReactEventRe.Synthetic.t => unit)=?,
      ~_open: option(bool)=?,
      ~renderValue: option('any_rxwk => ReasonReact.reactElement)=?,
      ~_SelectDisplayProps: option(Js.t({..}))=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(
                 array([ | `String(string) | `Int(int) | `Float(float)]),
               )
           ],
         )=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue:
         option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(ReasonReact.reactElement)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_ro5v)=?,
      ~inputRef: option('genericCallback)=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onEmpty: option('genericCallback)=?,
      ~onFilled: option('genericCallback)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEventRe.Keyboard.t => unit)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(ReasonReact.reactElement)=?,
      ~_type: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~autoWidth?,
        ~displayEmpty?,
        ~input?,
        ~inputProps?,
        ~_MenuProps?,
        ~multiple?,
        ~native?,
        ~onChange?,
        ~onClose?,
        ~onOpen?,
        ~_open?,
        ~renderValue?,
        ~_SelectDisplayProps?,
        ~value=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), value),
        ~autoComplete?,
        ~autoFocus?,
        ~className?,
        ~defaultValue=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            defaultValue,
          ),
        ~disabled?,
        ~disableUnderline?,
        ~endAdornment?,
        ~error?,
        ~fullWidth?,
        ~id?,
        ~inputComponent?,
        ~inputRef?,
        ~margin=?Js.Option.map((. v) => marginToJs(v), margin),
        ~multiline?,
        ~name?,
        ~onBlur?,
        ~onEmpty?,
        ~onFilled?,
        ~onFocus?,
        ~onKeyDown?,
        ~onKeyUp?,
        ~placeholder?,
        ~readOnly?,
        ~rows=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), rows),
        ~rowsMax=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            rowsMax,
          ),
        ~startAdornment?,
        ~_type?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
