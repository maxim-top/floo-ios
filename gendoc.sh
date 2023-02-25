#!/bin/bash
appledoc \
-m \
--output ./Doc \
-i *.m \
--project-name "floo-iOS" \
--project-company "美信拓扑" \
--no-create-docset \
--keep-undocumented-objects \
--keep-undocumented-members \
--no-warn-undocumented-object \
--no-warn-undocumented-member \
src/floo_proxy.h \
#../Products/floo-ios/floo/floo-ios.framework/Headers
for i in `find Doc/markdown -name "*.md"`
do
    if [[ $i == *._* ]]
    then
        continue
    fi
    echo '===1:'$i
    gawk 'BEGIN{TASK=0}{if($0~"^## .*" && TASK==1){TASK=0};if($0~"^## Tasks.*"){TASK=1};if(TASK==0){print $0}}' $i > $i".bak"
    mv $i".bak" $i
    sed -i .bak 's/\.html/.md/g' $i
    sed -i .bak 's/&quot;/"/g' $i
    sed -i .bak 's/&amp;/&/g' $i
    sed -i .bak 's/&lt;/</g' $i
    sed -i .bak 's/&gt;/>/g' $i
    sed -i .bak 's/&nbsp;/ /g' $i
done
find Doc/markdown/ -name "*.md.bak" -exec rm -rf {} \;
find Doc -name ".*.md" -exec rm {} \;
