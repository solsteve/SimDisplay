project:          SimDisplay
summary:          ![CALLISTO](|media|/projectlogo.png)
author:           First M. Last
src_dir:          ../local
output_dir:       ./html/publish/
media_dir:        ./media
exclude_dir:      ../apps
favicon:          ./media/callisto-032.png
project_github:   https://github.com/solsteve
project_download: https://github.com/solsteve
github:           https://github.com
website:          http://www.soliday.com/stephen
preprocessor:     gcc -E
predocmark_alt:   >
predocmark:       <
docmark_alt:
docmark:          !
display:          public
                  protected
                  private
source:           true
graph:            true
sort:             alpha
coloured_edges:   true
print_creation_date: true
creation_date:    %Y-%m-%d %H:%M %z

md_extensions: markdown.extensions.toc(anchorlink=False)
               markdown.extensions.smarty(smart_quotes=False)

# A modern C++ application.

This is a modern C++ application compatable with the Calisto Core4 library.
