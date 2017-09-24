let pathFor route =>
  switch route {
  | Routes.AlertExampleRoute => "/alert"
  | Routes.BadgesExampleRoute => "/badges"
  | Routes.BreadcrumbExampleRoute => "/breadcrumbs"
  | Routes.ButtonExampleRoute => "/buttons"
  | Routes.CollapseExampleRoute => "/collapse"
  | Routes.DropdownExampleRoute => "/dropdown"
  | Routes.FormExampleRoute => "/forms"
  | Routes.ModalExampleRoute => "/modal"
  | Routes.PaginationExampleRoute => "/pagination"
  | Routes.ProgressExampleRoute => "/progress"
  | Routes.TableExampleRoute => "/tables"
  };

let _to router route => {
  let path = pathFor route;
  DirectorRe.setRoute router path
};