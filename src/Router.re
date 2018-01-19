let handlers = (cb) => {
  "/alert": () => cb(Routes.AlertExampleRoute),
  "/badges": () => cb(Routes.BadgesExampleRoute),
  "/buttons": () => cb(Routes.ButtonExampleRoute),
  "/breadcrumbs": () => cb(Routes.BreadcrumbExampleRoute),
  "/collapse": () => cb(Routes.CollapseExampleRoute),
  "/dropdown": () => cb(Routes.DropdownExampleRoute),
  "/forms": () => cb(Routes.FormExampleRoute),
  "/modal": () => cb(Routes.ModalExampleRoute),
  "/pagination": () => cb(Routes.PaginationExampleRoute),
  "/progress": () => cb(Routes.ProgressExampleRoute),
  "/tables": () => cb(Routes.TableExampleRoute), 
  "/tabs": () => cb(Routes.TabExampleRoute)
};

let router = (cb) => DirectorRe.makeRouter(handlers(cb)); /* {"/": "home", "/alert":"alert", "/user": "user"}; */

let elementForRoute = (route) =>
  switch route {
  | Routes.AlertExampleRoute => <AlertExample message="This is an alert" />
  | Routes.BadgesExampleRoute => <BadgesExample />
  | Routes.BreadcrumbExampleRoute => <BreadcrumbExample />
  | Routes.ButtonExampleRoute => <ButtonExample />
  | Routes.CollapseExampleRoute => <Examples.CollapseExample />
  | Routes.DropdownExampleRoute => <Examples.DropdownExample />
  | Routes.FormExampleRoute => <Examples.FormExample />
  | Routes.ModalExampleRoute => <Examples.ModalExample />
  | Routes.PaginationExampleRoute => <Examples.PaginationExample />
  | Routes.ProgressExampleRoute => <Examples.ProgressExample />
  | Routes.TableExampleRoute => <Examples.TableExample />
  | Routes.TabExampleRoute => <Examples.TabsExample />
  };
