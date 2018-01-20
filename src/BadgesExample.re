include WidgetPlaying.Bootstrap;

let code: string =
  [%bs.raw {|require('./BadgesExample.re')|}] |> Examples.prepCode;

let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("BadgesExample");

let make = _children => {
  ...component,
  render: _self =>
    <Examples.Example title="Badges">
      <Badge color=Colors.Color.Primary> (se("Default")) </Badge>
      (Examples.exampleHighlight(code))
    </Examples.Example>
};