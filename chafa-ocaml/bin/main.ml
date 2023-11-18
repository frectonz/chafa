external draw_image : string -> int -> int -> string = "draw_image"

let () =
  draw_image "/home/frectonz/workspace/chafa/chafa-sys/frectonz.png" 100 100
  |> print_endline
