external draw_image : string -> string = "draw_image"

let () =
  draw_image "/home/frectonz/workspace/chafa/chafa-sys/frectonz.png"
  |> print_endline
