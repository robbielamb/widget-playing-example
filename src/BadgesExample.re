open WidgetPlaying;

include WidgetPlaying.Bootstrap;

let code: string = [%bs.raw {|require('./BadgesExample.re')|}];

let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("BadgesExample");

let make = _children => {
  ...component,
  render: _self =>
    <Examples.Example title="Badges">
      <Bootstrap.Badge color=Bootstrap.Colors.Color.Primary>
        (se("Default"))
      </Bootstrap.Badge>
      (Examples.exampleHighlight(code))
    </Examples.Example>
};