mkdir -p processed;

# combine herpes sprites side-by-side
gm convert herpes/herpes-small.png\
 herpes/herpes-small-king.png\
 -crop 8x8\
 +append processed/herpes_8.png;

# get width of combined sprites
WIDTH=$(gm identify -format %w processed/herpes_8.png)

# extend sprites to 8x16
gm convert processed/herpes_8.png\
 -gravity North\
 -background white\
 -extent ${WIDTH}x16\
 processed/herpes_16.png;

##
# do the same for herpes death animation
##
gm convert herpes/herpes-die.png\
 -crop 8x8\
 +append processed/herpes-die_8.png;

# get width of combined sprites
WIDTH=$(gm identify -format %w processed/herpes-die_8.png)

# extend sprites to 8x16
gm convert processed/herpes-die_8.png\
 -gravity North\
 -background white\
 -extent ${WIDTH}x16\
 processed/herpes-die_16.png;


# combine all sprites side-by-side
gm convert processed/herpes_16.png\
 @files.txt\
 processed/herpes-die_16.png\
 -crop 8x16\
 +append processed/appended.png;

gm convert processed/appended.png\
 -crop 128x16\
 -background black\
 -append processed/allcombined.png;
