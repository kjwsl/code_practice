use std::io::prelude::*;
use std::os::unix::net::{UnixListener, UnixStream};
use std::path::Path;

fn handle_client(stream: &mut UnixStream) -> std::io::Result<()> {
    let mut buffer = [0u8; 1024];

    let bytes_read = stream.read(&mut buffer)?;
    if bytes_read == 0 {
        return Ok(());
    }

    let received = String::from_utf8_lossy(&buffer[..bytes_read]);
    println!("Received: {}", received);

    stream.write_all(b"Echo: ")?;
    stream.write_all(&buffer[..bytes_read])?;
    println!("Sent: {}", received);

    Ok(())
}

fn main() -> std::io::Result<()> {
    let socket_path = "/tmp/rust_uds.sock";

    if Path::new(socket_path).exists() {
        std::fs::remove_file(socket_path)?;
    }

    let listener = UnixListener::bind(socket_path)?;
    println!("Server listening on {}", socket_path);

    for stream in listener.incoming() {
        match stream {
            Ok(mut stream) => {
                println!("New client connected");
                handle_client(&mut stream)?;
            }
            Err(err) => {
                eprintln!("Error accepting connection: {}", err);
                break;
            }
        }
    }

    Ok(())
}
