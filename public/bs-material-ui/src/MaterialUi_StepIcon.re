module Classes = {
  type classesType =
    | Root(string)
    | Text(string)
    | Active(string)
    | Completed(string)
    | Error(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Text(_) => "text"
    | Active(_) => "active"
    | Completed(_) => "completed"
    | Error(_) => "error";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Text(className)
                         | Active(className)
                         | Completed(className)
                         | Error(className) =>
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
    ~active: bool=?,
    ~completed: bool=?,
    ~error: bool=?,
    ~icon: React.element,
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
      ~active: option(bool)=?,
      ~completed: option(bool)=?,
      ~error: option(bool)=?,
      ~icon: React.element,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~active?,
    ~completed?,
    ~error?,
    ~icon,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "StepIcon";
