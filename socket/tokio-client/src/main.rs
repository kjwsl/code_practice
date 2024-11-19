use std::path::Path;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::UnixStream;

#[tokio::main]
async fn main() -> std::io::Result<()> {
    let socket_path = "/tmp/rust_uds_async.sock";

    // Check if the server socket exists
    if !Path::new(socket_path).exists() {
        eprintln!("Server socket does not exist at {}", socket_path);
        return Ok(());
    }

    // Connect to the server
    let mut stream = UnixStream::connect(socket_path).await?;
    println!("Connected to the async server");

    // Send a message to the server
    let message = "Hello from the async client!";
    stream.write_all(message.as_bytes()).await?;
    println!("Sent message: {}", message);

    // Read the response
    let mut buffer = [0u8; 1024];
    let bytes_read = stream.read(&mut buffer).await?;
    if bytes_read == 0 {
        println!("Server closed the connection");
        return Ok(());
    }

    let response = String::from_utf8_lossy(&buffer[..bytes_read]);
    println!("Received response: {}", response);

    Ok(())
}
