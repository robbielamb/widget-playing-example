[%bs.raw {|require('bootstrap/dist/css/bootstrap.css')|}];
[%bs.raw {|require('highlight.js/styles/default.css')|}];
[%bs.raw {|require('highlight.js/styles/solarized-dark.css')|}];

external register_service_worker : unit => unit =
  "default" [@@bs.module "./registerServiceWorker"];


ReactDOMRe.renderToElementWithId <Shell  /> "root";

/*
 DirectorRe.configure router {"html5history": true, "resource": handlers};

 DirectorRe.init router "/"; */
register_service_worker ();