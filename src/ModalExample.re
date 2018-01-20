include WidgetPlaying.Bootstrap;

let code: string =
  [%bs.raw {|require('./ModalExample.re')|}] |> Examples.prepCode;

let se = ReasonReact.stringToElement;

type action =
  | Toggle;
type state = bool;
let toggle = (event) => {
  Js.log2("Toggling modal", event);
  Toggle
};
let component = ReasonReact.reducerComponent("ButtonExample");
let make = (_children) => {
  ...component,
  initialState: () => false,
  reducer: (action, state) =>
    switch action {
    | Toggle => ReasonReact.Update(! state)
    },
  render: ({state, reduce}) =>
    <Examples.Example title="Modal">
      <Button color=Button.Color.Danger onClick=(reduce(toggle))> (se("Launch Modal")) </Button>
      <Modal isOpen=state>
        <Modal.Header toggle=(reduce(toggle))> (se("Modal Header")) </Modal.Header>
        <Modal.Body> (se("This is the modal body where I can put stuff")) </Modal.Body>
        <Modal.Footer>
          <Button color=Button.Color.Primary onClick=(reduce(toggle))>
            (se("Do Something"))
          </Button>
          <Button color=Button.Color.Secondary onClick=(reduce(toggle))> (se("Cancel")) </Button>
        </Modal.Footer>
      </Modal>
      (Examples.exampleHighlight(code))
    </Examples.Example>
};