external highlightClass : ReasonReact.reactClass =
  "default" [@@bs.module "react-fast-highlight"];

let make
    className::(className: option string)=?
    languages::(languages: option (array string))=?
    children =>
  ReasonReact.wrapJsForReason
    reactClass::highlightClass
    props::{
      "className": Js.Null_undefined.from_opt className,
      "languages": Js.Null_undefined.from_opt languages
    }
    children;