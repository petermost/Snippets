
namespace CSharpAidKit.IO
{
    using System;
    using Xunit;
    using static System.Runtime.InteropServices.RuntimeInformation;
    using static System.Runtime.InteropServices.OSPlatform;

    public class PathTest
    {
        #region Constructor tests:

        [Fact]
        public void TestOneParameterConstructor()
        {
            var path = new Path("parent");
            AssertPath("parent", path);
        }

        [Fact]
        public void TestTwoParameterConstructor()
        {
            var path = new Path("parent", "child");
            AssertPath("parent/child", path);
        }

        [Fact]
        public void TestThreeParameterConstructor()
        {
            var path = new Path("parent", "child", "filename");
            AssertPath("parent/child/filename", path);
        }

        [Fact]
        public void TestFourParameterConstructor()
        {
            var path = new Path("c:", "parent", "child", "filename.ext");
            AssertPath("c:/parent/child/filename.ext", path);
        }

        [Fact]
        public void TestVariableParameterConstructor()
        {
            var path = new Path(new[] { "d:", "parent", "child", "filename.ext" });
            AssertPath("d:/parent/child/filename.ext", path);
        }

        #endregion

        #region Property tests:

        [Fact]
        public void TestIsRooted()
        {
            if (IsOSPlatform(Windows)) {
                var path = new Path("r:\\parent\\child");
                Assert.True(path.IsRooted);
            } else if (IsOSPlatform(Linux)) {
                var path = new Path("/root/parent/child");
                Assert.True(path.IsRooted);
            }
        }

        [Fact]
        public void TestRoot()
        {
            if (IsOSPlatform(Windows)) {
                var path = new Path("r:", "parent", "child");
                AssertPath("r:/", path.Root);
            } else if (IsOSPlatform(Linux)) {
                var path = new Path("/root", "parent", "child");
                AssertPath("/", path.Root);
            }
        }

        [Fact]
        public void TestDirectoryName()
        {
            var path = new Path("parent", "child", "filename.ext");
            AssertPath("parent/child", path.DirectoryName);
        }

        [Fact]
        public void TestFileName()
        {
            var path = new Path("parent", "child", "filename.ext");
            AssertPath("filename.ext", path.FileName);
        }

        [Fact]
        public void TestFileNameWithoutExtension()
        {
            var path = new Path("parent", "child", "filename.ext");
            AssertPath("filename", path.FileNameWithoutExtension);
        }

        [Fact]
        public void TestHasExtension()
        {
            var path = new Path("filename.ext");
            Assert.True(path.HasExtension);
        }

        [Fact]
        public void TestHasEmptyExtension()
        {
            var path = new Path("filename");
            Assert.False(path.HasExtension);
        }


        [Fact]
        public void TestExtension()
        {
            var path = new Path("child", "filename.xyz");
            AssertPath(".xyz", path.Extension);
        }

        [Fact]
        public void TestEmptyExtension()
        {
            var path = new Path("child", "filename");
            AssertPath("", path.Extension);
        }

        [Fact]
        public void TestFullPath()
        {
            var path = new Path("parent", "child");
            AssertPath(Environment.CurrentDirectory + "/parent/child", path.FullPath);
        }

        [Fact]
        public void TestIsFullyQualified()
        {
            if (IsOSPlatform(Windows)) {
                var path = new Path("r:\\parent\\child");
                Assert.True(path.IsFullyQualified);
            } else if (IsOSPlatform(Linux)) {
                var path = new Path("/root/parent/child");
                Assert.True(path.IsFullyQualified);
            }
        }

        #endregion

        #region Modifier tests:

        [Fact]
        public void TestChangeExtension()
        {
            var path = new Path("parent", "child", "filename.old");
            path = path.ChangeExtension(".new");
            AssertPath("parent/child/filename.new", path);
        }

        [Fact]
        public void TestGetFullPathWithBase()
        {
            var path = new Path("parent", "child");
            if (IsOSPlatform(Windows))
                AssertPath("b:/parent/child", path.GetFullPath("b:\\"));
            else if (IsOSPlatform(Linux))
                AssertPath("/root/parent/child", path.GetFullPath("/root/"));
        }

        [Fact]
        public void TestGetRelativePath()
        {
            var path = new Path("parent", "child", "filename.ext");
            var relativeTo = new Path("parent");

            AssertPath("child/filename.ext", path.GetRelativePath(relativeTo));
        }

        #endregion

        #region Operator tests:

        [Fact]
        public void TestExplicitToStringConversion()
        {
            Path path = new Path("");
            string str = (string)path;
            Assert.NotNull(str);
        }

        [Fact]
        public void TestImplicitToFilePathConversion()
        {
            string str = "";
            Path path = str;
            Assert.NotNull(path);
        }

        [Fact]
        public void TestConstructorConcatenationOfPathAndString()
        {
            Path path = new Path("parent") / "child" / "filename.ext";
            AssertPath("parent/child/filename.ext", path);
        }

        [Fact]
        public void TestConstructorConcatenationOfPathAndPath()
        {
            var directory = new Path("parent", "child");
            var fileName = new Path("filename.ext");
            var path = directory / fileName;
            AssertPath("parent/child/filename.ext", path);
        }

        [Fact]
        public void TestCastingConcatenationOfPathAndString()
        {
            Path path = (Path)"parent" / "child" / "filename.ext";
            AssertPath("parent/child/filename.ext", path);
        }

        [Fact]
        public void TestAppendingOfPathAndString()
        {
            Path path = new Path("parent");
            path /= "child";
            AssertPath("parent/child", path);
        }

        [Fact]
        public void TestAppendingOfPathAndPath()
        {
            Path parent = new Path("parent");
            Path child = new Path("child");
            Path path = parent /= child;
            AssertPath("parent/child", path);
        }

        #endregion

        [Fact]
        public void TestEquals()
        {
            var path1 = new Path("parent", "child", "name");
            var path2 = new Path("parent", "child", "name");

            Assert.Equal(path1, path2);
        }

        private static void AssertPath(string expectedPath, Path actualPath)
        {
            Assert.Equal(MakeNativePath(expectedPath), actualPath.ToString());
        }

        private static string MakeNativePath(string path)
        {
            return path.Replace('/', System.IO.Path.DirectorySeparatorChar);
        }

    }
}
