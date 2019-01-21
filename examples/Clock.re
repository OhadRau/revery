open Revery.Core;
open Revery.UI;
open Revery.Math;

let numberLabel(radius, number) {
  let angle = float(number) *. 30.0 -. 90.0;
  let radians = x => x *. 3.14 /. 180.0;
  let x = int_of_float(radius *. cos(radians(angle)));
  let y = int_of_float(radius *. sin(radians(angle)));
  let style = Style.make(
    ~position=LayoutTypes.Absolute,
    ~top=260 + y,
    ~left=345 + x,
    ~backgroundColor=Colors.white,
    ~color=Colors.black,
    ~fontFamily="Roboto-Regular.ttf",
    ~fontSize=12,
    ()
  );
  <Text style text=(string_of_int(number))/>
};

let baseStyle = Style.make(~position=LayoutTypes.Absolute, ~left=350);

/* y center = 260 = 200 + (80/2) + (40/2) */
let hourHandStyle = clock =>
  baseStyle(~bottom=200, ~backgroundColor=Colors.black, ~width=4, ~height=80, ~transform=[RotateZ(Angle.from_degrees(float(clock.Unix.tm_hour mod 12) *. 30.0)), TranslateY(-40.0)], ());

/* y center = 260 = x + (100/2) + (50/2) */
let minuteHandStyle = clock =>
  baseStyle(~bottom=185, ~backgroundColor=Colors.black, ~width=4, ~height=100, ~transform=[RotateZ(Angle.from_degrees(float(clock.Unix.tm_min) *. 6.0)), TranslateY(-50.0)], ());

/* y center = 260 = 180 + (120/2) + (40/2) */
let secondHandStyle = clock =>
  baseStyle(~bottom=180, ~backgroundColor=Colors.red, ~width=2, ~height=120, ~transform=[RotateZ(Angle.from_degrees(float(clock.Unix.tm_sec) *. 6.0)), TranslateY(-40.0), TranslateX(1.0)], ());

let render = () => {
  let clock = Unix.(time() |> localtime);

  <View style=(Style.make(~position=LayoutTypes.Absolute, ~bottom=50, ~top=50, ~left=50, ~right=50, ~backgroundColor=Colors.white, ()))>
    <View style=hourHandStyle(clock) />
    <View style=minuteHandStyle(clock) />
    <View style=secondHandStyle(clock) />
    <View> ...(List.map(numberLabel(120.0), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])) </View>
  </View>
};
