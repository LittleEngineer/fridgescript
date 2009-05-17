using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Linq;
using System.Text;

namespace FridgeScript
{
    class API
    {
        [DllImport("FridgeScript", EntryPoint = "FSCreateContext", CallingConvention=CallingConvention.StdCall)]
        public extern static UInt32 FSCreateContext();

        [DllImport("FridgeScript", EntryPoint = "FSDestroyContext", CallingConvention = CallingConvention.StdCall)]
        public extern static UInt32 FSDestroyContext(UInt32 Context);

        [DllImport("FridgeScript", EntryPoint = "FSCompile", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public extern static UInt32 FSCompile(UInt32 Context, String Script);

        [DllImport("FridgeScript", EntryPoint = "FSExecute", CallingConvention = CallingConvention.StdCall)]
        public extern static UInt32 FSExecute(UInt32 Context, UInt32 CodeHandle);

        [DllImport("FridgeScript", EntryPoint = "FSGetVariableHandle", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public extern static UInt32 FSGetVariableHandle(UInt32 Context, UInt32 CodeHandle, String Name);

        [DllImport("FridgeScript", EntryPoint = "FSGetVariableValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public extern static Double FSGetVariableValue(UInt32 VariableHandle);

        [DllImport("FridgeScript", EntryPoint = "FSSetVariableValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public extern static Double FSSetVariableValue(UInt32 VariableHandle, Double value);
    }

    class Variable
    {
        Context Context;
        Code Code;
        
        public Variable(Context context, Code code, String name)
        {
            Context = context; Code = code; Name = name;
            Handle = API.FSGetVariableHandle(Context.Handle, Code.Handle, Name);
        }

        public UInt32 Handle { get; private set; }
        public String Name { get; private set; }
        public Double Value { get { return API.FSGetVariableValue(Handle); } set { API.FSSetVariableValue(Handle, value); } }
    }

    class Context
    {
        public class CodeList
        {
            private List<Code> List;
            private Context Context;

            public CodeList(Context context)
            {
                List = new List<Code>();
                Context = context;
            }
            public void Add(String Code)
            {
                List.Add(new Code(Context, Code));
            }

            public Code Find(Predicate<Code> Match)
            {
                return List.Find(Match);
            }

            public Code this[int Index]
            {
                get { return List[Index]; }
                set { List[Index] = value; }
            }
        }

        public Context()
        {
            Handle = API.FSCreateContext();
            Programs = new CodeList(this);
        }

        ~Context()
        {
            API.FSDestroyContext(Handle);
        }

        public UInt32 Handle { get; private set; }
        public CodeList Programs { get; private set; }
    }

    class Code
    {
        private Context Context;
        private String script;
        public String Script { get { return script; } set { script = value; Handle = API.FSCompile(Context.Handle, script); } }

        public Code(Context context, String code)
        {
            Context = context;
            Script = code;
        }

        public UInt32 Handle { get; private set; }
        
        public void Execute()
        {
            API.FSExecute(Context.Handle, Handle);
        }

        public Variable GetVariable(String Name)
        {
            return new Variable(Context, this, Name);
        }
    }

    class Compiler
    {
    }
}
