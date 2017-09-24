

let handlers cb => {
  "/alert": fun () => cb Routes.AlertExampleRoute,
  "/badges" : fun () => cb Routes.BadgesExampleRoute,
  "/buttons": fun () => cb Routes.ButtonExampleRoute,
  "/breadcrumbs": fun () => cb Routes.BreadcrumbExampleRoute,
  "/collapse": fun () => cb Routes.CollapseExampleRoute,
  "/dropdown": fun () => cb Routes.DropdownExampleRoute,
  "/forms": fun () => cb Routes.FormExampleRoute,
  "/modal": fun () => cb Routes.ModalExampleRoute,
  "/pagination": fun () => cb Routes.PaginationExampleRoute,
  "/progress": fun () => cb Routes.ProgressExampleRoute,
  "/tables": fun () => cb Routes.TableExampleRoute,
};

let router cb => DirectorRe.makeRouter (handlers cb); /* {"/": "home", "/alert":"alert", "/user": "user"}; */

let elementForRoute route router =>
  switch route {
  | Routes.AlertExampleRoute => <App.AlertExample message="This is an alert" />
  | Routes.BadgesExampleRoute => <App.BadgesExample />
  | Routes.BreadcrumbExampleRoute => <App.BreadcrumbExample />
  | Routes.ButtonExampleRoute => <App.ButtonExample />
  | Routes.CollapseExampleRoute => <App.CollapseExample />
  | Routes.DropdownExampleRoute => <App.DropdownExample />
  | Routes.FormExampleRoute => <App.FormExample />
  | Routes.ModalExampleRoute => <App.ModalExample />
  | Routes.PaginationExampleRoute => <App.PaginationExample />
  | Routes.ProgressExampleRoute => <App.ProgressExample />
  | Routes.TableExampleRoute => <App.TableExample />
  };

