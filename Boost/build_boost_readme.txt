- Extract the boost archive.

- Add the boost files to a local git repository:
	$ git init
	$ git add .
	$ git commit -m "initial commit"

- Bootstrap the build system according to www.boost.org/doc/libs/release/more/getting_started/windows.html

- Build with:
	$ b2 -j 4 variant=debug,release link=shared,static threading=single,multi

- Copy the *.pdb files from the '$BOOST_ROOT/bin.v2/libs/*' folders to '$BOOST_ROOT/stage/lib'

- Add the '$BOOST_ROOT/stage/lib' to the local git repository
	$ git add stage
	$ git commit -m "added binaries"

- Remove all intermediate files:
	$ git clean -d -f

- Move or remove the .git directory

- Deliver boost e.g. as a zip.

-- Written by P. Most

Build problems with 1.55:

- VC2013 build error /boost/archive/iterators/transform_width.hpp (https://svn.boost.org/trac/boost/ticket/9421)
- Boost.Serialization lacks algorithm header include for std::min (https://svn.boost.org/trac/boost/ticket/8757)
- decltype N3276 for MSVC12 + compile fix for tests (https://svn.boost.org/trac/boost/ticket/9410)

