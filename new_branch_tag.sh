ver=$1
git checkout floo2-iOS
git stash
git checkout -b 'v'$ver
git push --set-upstream origin 'v'$ver
git tag -a 'v'$ver -m 'v'$ver
git push --tags
git checkout floo2-iOS
git stash pop
