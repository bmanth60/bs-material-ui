[@bs.obj]
external makeProps :
  (
    ~container: 'union_rs0t=?,
    ~onRendered: ReactEventRe.Synthetic.t => unit=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Portal/Portal"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~onRendered: option(ReactEventRe.Synthetic.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~container=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            container,
          ),
        ~onRendered?,
        (),
      ),
    children,
  );
