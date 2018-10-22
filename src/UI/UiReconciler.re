/* Reconciler.re
 * 
 * This implements a reconciler for our UI primitives
 */

open Revery_Core;

type primitives = 
    | View
    | Text
    | Image;


type node = Node.node;

let createInstance = (prim) => {
    let node = switch (prim) {
    | View => new ViewNode.viewNode("test")
    | _ => new Node.node("test");
    };

    node#setStyle(Style.make(~width=50, ~height=50, ~backgroundColor=(Color.rgb(0.0, 1.0, 1.0)), ()));
    node
};

let appendChild = (parent: node, child: node) => {
    parent#addChild(child);
};

let removeChild = (parent: node, child: node) => {
    parent#removeChild(child);
};

let updateInstance = () => {
    print_endline ("TODO: updateElement");
};

let replaceChild = (parent: node, newChild: node, oldChild: node) => {
    removeChild(parent, oldChild);
    appendChild(parent, newChild);
    ()
};
