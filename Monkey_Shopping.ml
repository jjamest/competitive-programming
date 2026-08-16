let solve a b c d = 
  let needs_sugar = a < b in
  let needs_toothpaste = c < d in 
  match (needs_sugar, needs_toothpaste) with
  | (true, true) -> "Go to the department store"
  | (true, false) -> "Go to the grocery store"
  | (false, false) -> "Stay home"
  | (false, true) -> "Go to the pharmacy"

let () = Scanf.scanf "%d %d %d %d\n" (fun a b c d -> print_endline (solve a b c d))