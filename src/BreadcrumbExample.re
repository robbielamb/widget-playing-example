open WidgetPlaying;

include WidgetPlaying.Bootstrap;

let code: string = [%bs.raw {|require('./BreadcrumbExample.re')|}];

let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("BreadcrumbExample");

let make = _children => {
  ...component,
  render: _self =>
    <Examples.Example title="Breadcrumbs">
      <Bootstrap.BreadCrumb>
        <Bootstrap.BreadCrumb.Item> (se("home")) </Bootstrap.BreadCrumb.Item>
      </Bootstrap.BreadCrumb>
      <Bootstrap.BreadCrumb>
        <Bootstrap.BreadCrumb.Item> (se("home")) </Bootstrap.BreadCrumb.Item>
        <Bootstrap.BreadCrumb.Item active=true>
          (se("more"))
        </Bootstrap.BreadCrumb.Item>
      </Bootstrap.BreadCrumb>
      (Examples.exampleHighlight(code))
    </Examples.Example>
};