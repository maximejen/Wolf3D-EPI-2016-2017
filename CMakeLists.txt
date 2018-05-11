set(sources draw_minimap.c
        raycast2.c
        ob.c
        wolf.c
        free.c
        obj.c
        utility.c
        textures.c
        open_window.c
        my_getnbr.c
        load_textures.c
        move_mouse.c
        event_two.c
        my_strcat.c
        my_str_to_wordtab.c
        print_numbers.c
        load_texture2.c
        event.c
        main.c
        test.c
        load_texture3.c
        move_foward2.c
        src/move_forward.c
        src/my_draw_line.c
        src/raycast.c
        src/my_put_pixel.c
        include/wolf.h)

add_executable(wolf3d ${sources})