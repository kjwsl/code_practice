use std::{
    io::{Read, Write},
    os::unix::net::UnixStream,
    path::Path,
};

fn main() -> std::io::Result<()> {
    let socket_path = "/tmp/rust_uds.sock";

    if !Path::new(socket_path).exists() {
        eprintln!("The socket file does not exist");
        return Ok(());
    }

    let mut stream = UnixStream::connect(socket_path)?;
    println!("Connected to the server");

    let message = "Hello from the client!";
    stream.write_all(message.as_bytes())?;
    println!("Sent: {}", message);

    let mut buffer = [0u8; 1024];
    let bytes_read = stream.read(&mut buffer)?;
    if bytes_read == 0 {
        println!("The server closed the connection");
        return Ok(());
    }

    let response = String::from_utf8_lossy(&buffer[..bytes_read]);
    println!("Received: {}", response);

    Ok(())
}
