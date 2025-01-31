open Jest;
open Expect;

module Decimal = Relude.Decimal;
open Decimal;

describe("Decimal", () => {
  test("make", () =>
    expect(Decimal.make(12345, -2)) |> toEqual(Decimal(12345, -2))
  );

  test("fromInt", () =>
    expect(Decimal.fromInt(12345)) |> toEqual(Decimal(12345, 0))
  );

  test("show Decimal(12345, -2)", () =>
    expect(Decimal(12345, -2) |> Decimal.show) |> toEqual("123.45")
  );

  test("show Decimal(12345, 0)", () =>
    expect(Decimal(12345, 0) |> Decimal.show) |> toEqual("12345")
  );

  test("show Decimal(12345, 2)", () =>
    expect(Decimal(12345, 2) |> Decimal.show) |> toEqual("1234500")
  );

  test("tenToThePowerOfPositive -2", () =>
    expect(Decimal.tenToThePowerOfPositive(-2)) |> toEqual(1) // undefined
  );

  test("tenToThePowerOfPositive -1", () =>
    expect(Decimal.tenToThePowerOfPositive(-1)) |> toEqual(1) // undefined
  );

  test("tenToThePowerOfPositive 0 ", () =>
    expect(Decimal.tenToThePowerOfPositive(0)) |> toEqual(1)
  );

  test("tenToThePowerOfPositive 1 ", () =>
    expect(Decimal.tenToThePowerOfPositive(1)) |> toEqual(10)
  );

  test("tenToThePowerOfPositive 2 ", () =>
    expect(Decimal.tenToThePowerOfPositive(2)) |> toEqual(100)
  );

  test("tenToThePowerOfPositive 3 ", () =>
    expect(Decimal.tenToThePowerOfPositive(3)) |> toEqual(1000)
  );

  test("normalize", () => {
    let a = Decimal(12345, -2); // 123.45
    let b = Decimal(23456, 3); // 23456000
    let result = Decimal.normalize(a, b);
    expect(result)
    |> toEqual((Decimal(12345, -2), Decimal(2345600000, -2), (-2)));
  });

  test("add", () => {
    let a = Decimal(12345, -2); // 123.45
    let b = Decimal(23456, 3); // 23456000
    let result = Decimal.add(a, b);
    expect(result) |> toEqual(Decimal(2345612345, -2));
  });

  test("subtract", () => {
    let a = Decimal(12345, -2); // 123.45
    let b = Decimal(23456, 3); // 23456000
    let result = Decimal.subtract(a, b);
    expect(result) |> toEqual(Decimal(-2345587655, -2));
  });
});