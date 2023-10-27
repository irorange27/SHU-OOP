add_rules("mode.debug", "mode.release")

-- target("Template_LinkList")
--     set_kind("binary")
--     add_files("src/*.cpp")

for _, file in ipairs(os.files("test/test_*.cpp")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        set_default(true)
        add_files(file)
        add_tests("default")
    target_end()
end


-- target("test_iList")
--     set_kind("binary")
--     add_files("test/test_iList.cpp")
--     add_tests("test_iList")
--     set_group("test1")

-- target("test_node")
--     set_kind("binary")
--     add_files("test/test_node.cpp")
--     add_tests("test_node")
--     set_group("test2")



-- define toolchain
toolchain("myclang")

    -- mark as standalone toolchain
    set_kind("standalone")

    -- set toolset
    set_toolset("cc", "clang")
    set_toolset("cxx", "clang", "clang++")
    set_toolset("ld", "clang++", "clang")
    set_toolset("sh", "clang++", "clang")
    set_toolset("ar", "ar")
    set_toolset("ex", "ar")
    set_toolset("strip", "strip")
    set_toolset("mm", "clang")
    set_toolset("mxx", "clang", "clang++")
    set_toolset("as", "clang")

    add_defines("MYCLANG")

    -- check toolchain
    on_check(function (toolchain)
        return import("lib.detect.find_tool")("clang")
    end)

    -- on load
    on_load(function (toolchain)

        -- get march
        local march = is_arch("x86_64", "x64") and "-m64" or "-m32"

        -- init flags for c/c++
        toolchain:add("cxflags", march)
        toolchain:add("ldflags", march)
        toolchain:add("shflags", march)
        if not is_plat("windows") and os.isdir("/usr") then
            for _, includedir in ipairs({"/usr/local/include", "/usr/include"}) do
                if os.isdir(includedir) then
                    toolchain:add("includedirs", includedir)
                end
            end
            for _, linkdir in ipairs({"/usr/local/lib", "/usr/lib"}) do
                if os.isdir(linkdir) then
                    toolchain:add("linkdirs", linkdir)
                end
            end
        end
    end)
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

