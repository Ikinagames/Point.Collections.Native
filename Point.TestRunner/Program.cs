// See https://aka.ms/new-console-template for more information
using Point.Collections;
using Point.Collections.Buffer.LowLevel;
using Point.Collections.Native;

Console.WriteLine("Hello, World!");
Program Program = new Program();
Program.Main();

struct TestStruct
{
    public int x;
    public int y;
}

public unsafe partial class Program
{
    static Program()
    {

    }

    public void Main()
    {
        TestStruct x = new TestStruct(), y = x;
        void*
            a = NativeUtility.AddressOf(ref x),
            b = NativeUtility.AddressOf(ref y);

        bool result;
        NativeMath.binaryComparer(a, b, TypeHelper.SizeOf<TestStruct>(), &result);

        Console.WriteLine(result);
    }
}