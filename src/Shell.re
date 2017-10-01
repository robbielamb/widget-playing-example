type state = {
  currentRoute: Routes.t,
  router: option DirectorRe.t
};

type action =
  | SetRoute Routes.t
  | SetRouter DirectorRe.t
  | Open
  | Close;

let navTo router route event _self => {
  ReactEventRe.Mouse.preventDefault event;
  Navigate._to router route
};

let navNav handle router currentRoute routeTo name => {
  let href = Navigate.pathFor routeTo;
  let disabled = currentRoute === routeTo;
  let navTo = navTo router routeTo;
  let el =
    <Bootstrap.Nav.Link href disabled onClick=(handle navTo)>
      (ReasonReact.stringToElement name)
    </Bootstrap.Nav.Link>;
  el
};

let component = ReasonReact.reducerComponent "Shell";

let make _children => {
  ...component,
  initialState: fun () => {currentRoute: Routes.AlertExampleRoute, router: None},
  didMount: fun self => {
    let router = Router.router (fun x => self.reduce (fun () => SetRoute x) ());
    /* (self.reduce (fun () => (SetRouter router))(); */
    DirectorRe.configure router {"html5history": true};
    DirectorRe.init router "/alert";
    ReasonReact.Update {...self.state, router: Some router}
  },
  reducer: fun action state =>
    switch action {
    | SetRoute route => ReasonReact.Update {...state, currentRoute: route}
    | SetRouter router => ReasonReact.Update {...state, router: Some router}
    | _ => ReasonReact.NoUpdate
    },
  render: fun (self: ReasonReact.self state ReasonReact.noRetainedProps action) =>
    switch self.state.router {
    | None => ReasonReact.nullElement /* Loading..... */
    | Some router =>
      let element = Router.elementForRoute self.state.currentRoute;
      let navTo = navNav self.handle router self.state.currentRoute;
      <div>
        <Bootstrap.Navbar light=true>
          <Bootstrap.Navbar.Brand>
            (ReasonReact.stringToElement "Widget Play")
          </Bootstrap.Navbar.Brand>
        </Bootstrap.Navbar>
        <Bootstrap.Layout.Container>
          <Bootstrap.Layout.Row>
            <Bootstrap.Layout.Col> element </Bootstrap.Layout.Col>
            <Bootstrap.Layout.Col
              md=(Bootstrap.Layout.Col.shape size::(Bootstrap.Layout.ColSizes.Size 2) ())>
              <p> (ReasonReact.stringToElement "Select Example") </p>
              <Bootstrap.Nav vertical=true>
                <Bootstrap.Nav.Item>
                  (navTo Routes.AlertExampleRoute "Alerts")
                  (navTo Routes.BadgesExampleRoute "Badges")
                  (navTo Routes.BreadcrumbExampleRoute "Breadcrumbs")
                  (navTo Routes.ButtonExampleRoute "Buttons")
                  (navTo Routes.CollapseExampleRoute "Collapse")
                  (navTo Routes.DropdownExampleRoute "Dropdown")
                  (navTo Routes.FormExampleRoute "Forms")
                  (navTo Routes.ModalExampleRoute "Modals")        
                  (navTo Routes.PaginationExampleRoute "Pagination")          
                  (navTo Routes.ProgressExampleRoute "Progress Bars")
                  (navTo Routes.TableExampleRoute "Tables")
                  
                </Bootstrap.Nav.Item>
              </Bootstrap.Nav>
            </Bootstrap.Layout.Col>
          </Bootstrap.Layout.Row>
        </Bootstrap.Layout.Container>
      </div>
    }
};