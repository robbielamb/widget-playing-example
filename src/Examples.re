open Bootstrap;

external logo : string = "./logo.svg" [@@bs.module];

let se = ReasonReact.stringToElement;

let exampleHighlight code => <Highlight languages=[|"html"|]> (se code) </Highlight>;

module Example = {
  let component = ReasonReact.statelessComponent "Example";
  let make ::title (children: array ReasonReact.reactElement) => {
    ...component,
    render: fun _self => {
      let title = <h3> (se title) </h3>;
      let _ = Js.Array.unshift title children;
      let col = ReasonReact.element (Layout.Col.make children);
      <Layout.Row className="mb-4 border p-2"> col </Layout.Row>
    }
  };
};

module AlertExample = {
  type action =
    | Toggle;
  type state = bool;
  let toggle (event: ReactEventRe.Mouse.t) => {
    Js.log event;
    Toggle
  };
  let component = ReasonReact.statelessComponent "AlertExample";
  let make ::message _children => {
    ...component,
    render: fun _self =>
      <Example title="Alerts">
        <Bootstrap.Alert.Auto color=Bootstrap.Alert.Color.Primary>
          <Alert.Heading> (ReasonReact.stringToElement "Success") </Alert.Heading>
          <p> (ReasonReact.stringToElement message) </p>
        </Bootstrap.Alert.Auto>
        (
          exampleHighlight "<Bootstrap.Alert.Auto color=Bootstrap.Alert.Color.Primary>\n  <Alert.Heading> (ReasonReact.stringToElement \"Success\") </Alert.Heading>\n  <p> (ReasonReact.stringToElement \"This is an alert\") </p>\n</Bootstrap.Alert.Auto>"
        )
      </Example>
  };
};

module BadgesExample = {
  let component = ReasonReact.statelessComponent "BadgesExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Badges">
        <Bootstrap.Badge color=Bootstrap.Badge.Color.Primary> (se "Default") </Bootstrap.Badge>
        (
          exampleHighlight "<Bootstrap.Badge color=Bootstrap.Badge.Color.Primary>\n    (ReasonReact.stringToElement \"Default\")\n</Bootstrap.Badge>"
        )
      </Example>
  };
};

module BreadcrumbExample = {
  let component = ReasonReact.statelessComponent "BreadcrumbExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Breadcrumbs">
        <Bootstrap.BreadCrumb>
          <Bootstrap.BreadCrumb.Item> (se "home") </Bootstrap.BreadCrumb.Item>
        </Bootstrap.BreadCrumb>
        <Bootstrap.BreadCrumb>
          <Bootstrap.BreadCrumb.Item> (se "home") </Bootstrap.BreadCrumb.Item>
          <Bootstrap.BreadCrumb.Item active=true> (se "more") </Bootstrap.BreadCrumb.Item>
        </Bootstrap.BreadCrumb>
      </Example>
  };
};

module ButtonExample = {
  let component = ReasonReact.statelessComponent "ButtonExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Buttons">
        <Button color=Button.Color.Primary size=Button.Size.LG> (se "Primary") </Button>
        (se " ")
        <Button color=Button.Color.Secondary> (se "Secondary") </Button>
        (se " ")
        <Button color=Button.Color.Success> (se "Success") </Button>
        (se " ")
        <Button color=Button.Color.Info> (se "Info") </Button>
        (se " ")
        <Button color=Button.Color.Warning> (se "Warning") </Button>
        (se " ")
        <Button color=Button.Color.Danger> (se "Danger") </Button>
        (se " ")
        <Button color=Button.Color.Link> (se "Link") </Button>
      </Example>
  };
};

module CollapseExample = {
  type action =
    | Toggle
    | Opened
    | Closed;
  type state = {
    isOpen: bool,
    status: string
  };
  let component = ReasonReact.reducerComponent "CollapseExample";
  let make _children => {
    ...component,
    initialState: fun () => {isOpen: true, status: "Open"},
    reducer: fun action state =>
      switch action {
      | Toggle =>
        ReasonReact.Update {
          ...state,
          isOpen: not state.isOpen,
          status: not state.isOpen ? "Opening..." : "Collapsing..."
        }
      | Opened => ReasonReact.Update {...state, status: "Open"}
      | Closed => ReasonReact.Update {...state, status: "Closed"}
      },
    render: fun {state, reduce} =>
      <Example title="Collapse">
        <Button onClick=(reduce (fun _ => Toggle)) color=Button.Color.Primary>
          (se "Collapse")
        </Button>
        <p> (se state.status) </p>
        <Collapse
          isOpen=state.isOpen
          onOpened=(reduce (fun _ => Opened))
          onClosed=(reduce (fun _ => Closed))>
          <Card>
            <Card.Header> (se "This is the card header") </Card.Header>
            <Card.Body> (se "THis is card and some more and some more and some more!") </Card.Body>
          </Card>
        </Collapse>
      </Example>
  };
};

module DropdownExample = {
  type state = {isOpen: bool};
  type actions =
    | Toggle;
  let component = ReasonReact.reducerComponent "DropdownExample";
  let toggle (self: ReasonReact.self state ReasonReact.noRetainedProps actions) () => {
    Js.log "toggling";
    self.reduce (fun _ => Toggle) ()
  };
  let make _children => {
    ...component,
    initialState: fun () => {isOpen: false},
    reducer: fun action state =>
      switch action {
      | Toggle => ReasonReact.Update {isOpen: not state.isOpen}
      },
    render: fun self =>
      <Example title="Dropdowns">
        /*     <Dropdown isOpen=self.state.isOpen toggle=(toggle self)>
                 <Dropdown.Toggle isOpen=self.state.isOpen caret=true toggle=(toggle self)> (se "Dropdown! ") </Dropdown.Toggle>
                 <Dropdown.Menu isOpen=self.state.isOpen>
                   <Dropdown.Header> (se "Header") </Dropdown.Header>
                   <Dropdown.Item> (se "Another Action") </Dropdown.Item>
                   <Dropdown.Item> (se "Another Item") </Dropdown.Item>
                   <Dropdown.Divider />
                   <Dropdown.Item> (se "Last Item") </Dropdown.Item>
                 </Dropdown.Menu>
               </Dropdown> */

          <Dropdown isOpen=self.state.isOpen toggle=(toggle self)>
            <Dropdown.Toggle isOpen=self.state.isOpen caret=true toggle=(toggle self)>
              (se "align right! ")
            </Dropdown.Toggle>
            <Dropdown.Menu isOpen=self.state.isOpen alignRight=true>
              <Dropdown.Header> (se "Header") </Dropdown.Header>
              <Dropdown.Item> (se "Another Action") </Dropdown.Item>
              <Dropdown.Item disabled=true> (se "Disabled Action") </Dropdown.Item>
              <Dropdown.Item> (se "Another Item") </Dropdown.Item>
              <Dropdown.Divider />
              <Dropdown.Item> (se "Last Item") </Dropdown.Item>
            </Dropdown.Menu>
          </Dropdown>
        </Example>
  };
};

module FormExample = {
  let component = ReasonReact.statelessComponent "FormExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Forms & Input">
        <Form>
          <Form.Group>
            <Input.Label _for="exampleEmail"> (se "Email") </Input.Label>
            <Input
              _type=Input.Email
              name="email"
              id="exampleEmail"
              placeholder="with a placeholder"
            />
          </Form.Group>
          <Form.Group>
            <Input.Label _for="examplePassword"> (se "Password") </Input.Label>
            <Input
              _type=Input.Password
              name="email"
              id="examplePassword"
              placeholder="password here"
            />
          </Form.Group>
          <Form.Group>
            <Input.Label _for="selectExample"> (se "Select") </Input.Label>
            <Input _type=Input.Select name="select" id="selectExample" placeholder="foo">
              <option> (se "1") </option>
              <option> (se "2") </option>
              <option> (se "3") </option>
              <option> (se "4") </option>
            </Input>
          </Form.Group>
          <Form.Group>
            <Input.Label _for="selecMultitExample"> (se "Select Multiple") </Input.Label>
            <Input
              _type=Input.Select
              name="multi-select"
              id="selectMultiExample"
              placeholder="foo"
              multiple=true>
              <option> (se "1") </option>
              <option> (se "2") </option>
              <option> (se "3") </option>
              <option> (se "4") </option>
              <option> (se "5") </option>
              <option> (se "6") </option>
            </Input>
          </Form.Group>
          <Form.Group>
            <Input.Label _for="exampleTextArea"> (se "Text Area") </Input.Label>
            <Input
              _type=Input.TextArea
              name="textarea"
              id="exampleTextArea"
              placeholder="with a placeholder"
            />
          </Form.Group>
          <Form.Group>
            <Input.Label _for="exampleFile"> (se "File Upload Time") </Input.Label>
            <Input
              _type=Input.File
              name="file"
              id="exampleFile"
              placeholder="with a placeholder"
            />
            <Form.Text>
              (se "This is a bit of example text to help explain the dialog above.")
            </Form.Text>
          </Form.Group>
          <Form.Group tag="fieldset">
            <legend> (se "Hello Radio (buttons>") </legend>
            <Form.Check>
              <Input.Label check=true>
                <Input _type=Input.Radio name="radio1" />
                (se " Radio 1")
              </Input.Label>
            </Form.Check>
            <Form.Check>
              <Input.Label check=true>
                <Input _type=Input.Radio name="radio1" />
                (se " Radio 2")
              </Input.Label>
            </Form.Check>
            <Form.Check disabled=true>
              <Input.Label check=true>
                <Input _type=Input.Radio name="radio1" disabled=true />
                (se " Radio 3 - Disabled")
              </Input.Label>
            </Form.Check>
          </Form.Group>
          <Form.Check>
            <Input.Label check=true>
              <Input _type=Input.Checkbox name="check-box" />
              (se "  This is a checkbox")
            </Input.Label>
          </Form.Check>
        </Form>
      </Example>
  };
};

module ModalExample = {
  type action =
    | Toggle;
  type state = bool;
  let toggle event => {
    Js.log2 "Toggling modal" event;
    Toggle
  };
  let component = ReasonReact.reducerComponent "ButtonExample";
  let make _children => {
    ...component,
    initialState: fun () => false,
    reducer: fun action state =>
      switch action {
      | Toggle => ReasonReact.Update (not state)
      },
    render: fun {state, reduce} =>
      <Example title="Modal">
        <Button color=Button.Color.Danger onClick=(reduce toggle)> (se "Launch Modal") </Button>
        <Modal isOpen=state toggle=(reduce toggle)>
          <Modal.Header toggle=(reduce toggle)> (se "Modal Header") </Modal.Header>
          <Modal.Body> (se "This is the modal body where I can put stuff") </Modal.Body>
          <Modal.Footer>
            <Button color=Button.Color.Primary onClick=(reduce toggle)>
              (se "Do Something")
            </Button>
            <Button color=Button.Color.Secondary onClick=(reduce toggle)> (se "Cancel") </Button>
          </Modal.Footer>
        </Modal>
      </Example>
  };
};

module PaginationExample = {
  let component = ReasonReact.statelessComponent "PaginationExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Pagination">
        <Pagination size=Pagination.Size.Small>
          <Pagination.Item> <Pagination.Link previous=true href="#" /> </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "1") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item active=true>
            <Pagination.Link href="#"> (se "2") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "3") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item> <Pagination.Link next=true href="#" /> </Pagination.Item>
        </Pagination>
        <Pagination>
          <Pagination.Item> <Pagination.Link previous=true href="#" /> </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "1") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "2") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "3") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item> <Pagination.Link next=true href="#" /> </Pagination.Item>
        </Pagination>
        <Pagination size=Pagination.Size.Large>
          <Pagination.Item disabled=true>
            <Pagination.Link previous=true href="#" />
          </Pagination.Item>
          <Pagination.Item active=true>
            <Pagination.Link href="#"> (se "1") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "2") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item>
            <Pagination.Link href="#"> (se "3") </Pagination.Link>
          </Pagination.Item>
          <Pagination.Item> <Pagination.Link next=true href="#" /> </Pagination.Item>
        </Pagination>
      </Example>
  };
};

module ProgressExample = {
  let component = ReasonReact.statelessComponent "ProgressExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Progress Bars">
        <div className="text-center"> (se "0%") </div>
        <Progress />
        <div className="text-center"> (se "25%") </div>
        <Progress value=25.0 />
        <div className="text-center"> (se "50%") </div>
        <Progress value=50.0 />
        <div className="text-center"> (se "100%") </div>
        <Progress value=100.0 />
        <div className="text-center"> (se "73 of 108") </div>
        <Progress value=73.0 max=108.0> (se "70/108") </Progress>
        <div className="text-center"> (se "Multiple bars") </div>
        <Progress multi=true>
          <Progress bar=true value=15.0> (se "15%") </Progress>
          <Progress bar=true value=15.0 color=Progress.BackgroundColor.Success />
          <Progress bar=true value=15.0 color=Progress.BackgroundColor.Info />
          <Progress bar=true value=15.0 color=Progress.BackgroundColor.Warning />
          <Progress bar=true value=15.0 color=Progress.BackgroundColor.Danger />
        </Progress>
        <div className="text-center"> (se "Striped") </div>
        <Progress value=50.0 color=Progress.BackgroundColor.Info striped=true>
          (se "Striped")
        </Progress>
        <div className="text-center"> (se "Animated") </div>
        <Progress value=50.0 color=Progress.BackgroundColor.Danger animated=true>
          (se "Animated")
        </Progress>
      </Example>
  };
};

module TableExample = {
  let component = ReasonReact.statelessComponent "TableExample";
  let make _children => {
    ...component,
    render: fun _self =>
      <Example title="Table example">
        <Table bordered=true striped=true hover=true>
          <thead>
            <tr>
              <th> (se "Col 1") </th>
              <th> (se "Col 2") </th>
              <th> (se "Col 3") </th>
              <th> (se "Col 4") </th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td> (se "Row 1, col 1") </td>
              <td> (se "Row 1, col 2") </td>
              <td> (se "Row 1, col 3") </td>
              <td> (se "Row 1, col 4") </td>
            </tr>
            <tr>
              <td> (se "Row 2, col 1") </td>
              <td> (se "Row 2, col 2") </td>
              <td> (se "Row 2, col 3") </td>
              <td> (se "Row 2, col 4") </td>
            </tr>
            <tr>
              <td> (se "Row 3, col 1") </td>
              <td> (se "Row 3, col 2") </td>
              <td> (se "Row 3, col 3") </td>
              <td> (se "Row 3, col 4") </td>
            </tr>
            <tr>
              <td> (se "Row 4, col 1") </td>
              <td> (se "Row 4, col 2") </td>
              <td> (se "Row 4, col 3") </td>
              <td> (se "Row 4, col 4") </td>
            </tr>
          </tbody>
        </Table>
      </Example>
  };
};