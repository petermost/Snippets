
namespace CSharpAidKit.IO
{
    using Paths = System.IO.Path;

    public class Path
    {
        private readonly string m_pathName;

        #region Constructors:

        public Path(string path)
        {
            m_pathName = path;
        }

        public Path(string path1, string path2)
            : this(Paths.Combine(path1, path2))
        {
        }

        public Path(string path1, string path2, string path3)
            : this(Paths.Combine(path1, path2, path3))
        {
        }

        public Path(string path1, string path2, string path3, string path4)
            : this(Paths.Combine(path1, path2, path3, path4))
        {
        }

        public Path(params string[] paths)
            : this(Paths.Combine(paths))
        {
        }

        #endregion

        #region Properties

        public bool IsRooted
        {
            get => Paths.IsPathRooted(m_pathName);
        }

        public Path Root
        {
            get => new Path(Paths.GetPathRoot(m_pathName));
        }

        public Path DirectoryName
        {
            get => new Path(Paths.GetDirectoryName(m_pathName));
        }

        public Path FileName
        {
            get => new Path(Paths.GetFileName(m_pathName));
        }

        public Path FileNameWithoutExtension
        {
            get => new Path(Paths.GetFileNameWithoutExtension(m_pathName));
        }

        public bool HasExtension
        {
            get => Paths.HasExtension(m_pathName);
        }

        public Path Extension
        {
            get => new Path(Paths.GetExtension(m_pathName));
        }

        public bool IsFullyQualified
        {
            get => Paths.IsPathFullyQualified(m_pathName);
        }

        public Path FullPath
        {
            get => new Path(Paths.GetFullPath(m_pathName));
        }

        #endregion

        #region Modifiers:

        public Path ChangeExtension(string extension)
        {
            return new Path(Paths.ChangeExtension(m_pathName, extension));
        }

        public Path GetFullPath(string basePath)
        {
            return new Path(Paths.GetFullPath(m_pathName, basePath));
        }

        public Path GetRelativePath(Path relativeTo)
        {
            return new Path(Paths.GetRelativePath(relativeTo.ToString(), m_pathName));
        }

        #endregion

        #region Operators:

        public static implicit operator Path(string path)
        {
            return new Path(path);
        }

        public static explicit operator string(Path path)
        {
            return path.ToString();
        }

        public static Path operator / (Path path, string pathPart)
        {
            return new Path(path.ToString(), pathPart);
        }

        public static Path operator / (Path path1, Path path2)
        {
            return new Path(path1.ToString(), path2.ToString());
        }

        #endregion

        public override bool Equals(object other)
        {
            return ToString().Equals(other.ToString());
        }

        public override int GetHashCode()
        {
            return m_pathName.GetHashCode();
        }

        public override string ToString()
        {
            return m_pathName;
        }
    }
}
