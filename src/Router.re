

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

let elementForRoute route =>
  switch route {
  | Routes.AlertExampleRoute => <Examples.AlertExample message="This is an alert" />
  | Routes.BadgesExampleRoute => <Examples.BadgesExample />
  | Routes.BreadcrumbExampleRoute => <Examples.BreadcrumbExample />
  | Routes.ButtonExampleRoute => <Examples.ButtonExample />
  | Routes.CollapseExampleRoute => <Examples.CollapseExample />
  | Routes.DropdownExampleRoute => <Examples.DropdownExample />
  | Routes.FormExampleRoute => <Examples.FormExample />
  | Routes.ModalExampleRoute => <Examples.ModalExample />
  | Routes.PaginationExampleRoute => <Examples.PaginationExample />
  | Routes.ProgressExampleRoute => <Examples.ProgressExample />
  | Routes.TableExampleRoute => <Examples.TableExample />
  };

