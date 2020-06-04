[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "filled"] `Filled
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "standard"] `Standard
];

module Classes = {
  type classesType =
    | Root(string)
    | Select(string)
    | Filled(string)
    | Outlined(string)
    | SelectMenu(string)
    | Disabled(string)
    | Icon(string)
    | IconOpen(string)
    | IconFilled(string)
    | IconOutlined(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Select(_) => "select"
    | Filled(_) => "filled"
    | Outlined(_) => "outlined"
    | SelectMenu(_) => "selectMenu"
    | Disabled(_) => "disabled"
    | Icon(_) => "icon"
    | IconOpen(_) => "iconOpen"
    | IconFilled(_) => "iconFilled"
    | IconOutlined(_) => "iconOutlined";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Select(className)
                         | Filled(className)
                         | Outlined(className)
                         | SelectMenu(className)
                         | Disabled(className)
                         | Icon(className)
                         | IconOpen(className)
                         | IconFilled(className)
                         | IconOutlined(className) =>
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
    ~aria_describedby: string=?,
    ~className: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderSuffix: 'genericCallback=?,
    ~rowsMin: 'union_rurl=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~color: string=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~inputComponent: 'union_rkfv=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_rl6h=?,
    ~rowsMax: 'union_rr12=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~autoWidth: bool=?,
    ~children: 'children=?,
    ~defaultValue: 'any_rf48=?,
    ~displayEmpty: bool=?,
    ~_IconComponent: 'union_rvmf=?,
    ~id: string=?,
    ~input: React.element=?,
    ~inputProps: Js.t({..})=?,
    ~label: React.element=?,
    ~labelId: string=?,
    ~labelWidth: 'number_i=?,
    ~_MenuProps: Js.t({..})=?,
    ~multiple: bool=?,
    ~native: bool=?,
    ~onChange: 'any_r28u=?,
    ~onClose: 'any_r9er=?,
    ~onOpen: 'any_r1dm=?,
    ~_open: bool=?,
    ~renderValue: 'any_r2q4=?,
    ~_SelectDisplayProps: Js.t({..})=?,
    ~value: 'union_ri43=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~aria_describedby: option(string)=?,
      ~className: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderSuffix: option('genericCallback)=?,
      ~rowsMin: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~inputComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~rowsMax: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
      ~autoWidth: option(bool)=?,
      ~children: option('children)=?,
      ~defaultValue: option('any_rf48)=?,
      ~displayEmpty: option(bool)=?,
      ~_IconComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~id: option(string)=?,
      ~input: option(React.element)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~label: option(React.element)=?,
      ~labelId: option(string)=?,
      ~labelWidth: option([ | `Int(int) | `Float(float)])=?,
      ~_MenuProps: option(Js.t({..}))=?,
      ~multiple: option(bool)=?,
      ~native: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, Js.t({..})) => unit)=?,
      ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
      ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~renderValue: option('any_rlcu => 'any_rsc9)=?,
      ~_SelectDisplayProps: option(Js.t({..}))=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(array(string))
           ],
         )=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~aria_describedby?,
    ~className?,
    ~onBlur?,
    ~onClick?,
    ~onFocus?,
    ~onKeyDown?,
    ~onKeyUp?,
    ~renderSuffix?,
    ~rowsMin=?
      rowsMin->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~autoComplete?,
    ~autoFocus?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~disabled?,
    ~disableUnderline?,
    ~endAdornment?,
    ~error?,
    ~fullWidth?,
    ~inputComponent=?
      inputComponent->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
    ~margin=?margin->Belt.Option.map(v => marginToJs(v)),
    ~multiline?,
    ~name?,
    ~placeholder?,
    ~readOnly?,
    ~required?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~startAdornment?,
    ~_type=?type_,
    ~autoWidth?,
    ~children?,
    ~defaultValue?,
    ~displayEmpty?,
    ~_IconComponent=?
      _IconComponent->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
    ~id?,
    ~input?,
    ~inputProps?,
    ~label?,
    ~labelId?,
    ~labelWidth=?
      labelWidth->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_MenuProps?,
    ~multiple?,
    ~native?,
    ~onChange?,
    ~onClose?,
    ~onOpen?,
    ~_open=?open_,
    ~renderValue?,
    ~_SelectDisplayProps?,
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Select";
