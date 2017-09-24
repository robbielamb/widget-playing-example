[%bs.raw {|require('bootstrap/dist/css/bootstrap.css')|}];

external register_service_worker : unit => unit =
  "default" [@@bs.module "./registerServiceWorker"];


ReactDOMRe.renderToElementWithId <Shell  /> "root";

/*
 DirectorRe.configure router {"html5history": true, "resource": handlers};

 DirectorRe.init router "/"; */
register_service_worker ();